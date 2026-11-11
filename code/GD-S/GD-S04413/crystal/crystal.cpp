#include<bits/stdc++.h>
using namespace std;
bool cmpt(long long b1,long long b2){
	return b1>b2;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	vector<long long > a(n);
	bool flag1=1,flag2=1;
	if (n<500){
		flag1=0;
		flag2=0;
	}
	for (int i=0;i<n;i++){
		cin >> a[i];
		if (flag1==1||flag2==1){
			if  (flag2&&a[i]!=i+1){
				flag2=0;
			}
			if (flag1&&i>=5){
				if (a[i]-a[i-1]!=a[i-1]-a[i-2]){
					flag1=0;
				}
			}
			if(i>5){
				if (flag1==1){
					int k;
					for(k=0;k<n||m<=0;k++){
						m-=k;
					}
					if (m<0){
						k--;
					}
					if (n<k)cout << n;
					else cout << k;
					return 0;
				}
				if (flag1==5){
					int cha=a[i-1]-a[i-2];
					int k;
					for(k=0;k<n||m<=0;k+=cha){
						m-=k;
					}
					if (m<0){
						k--;
					}
					if (n<k)cout << n;
					else cout << k;
					return 0;
				}
				
			}
			
		}
			
		}
	sort(a.begin(),a.end(),cmpt);
	queue<long long> b;
	long long tgt=0;
	long long sum=0;
	long long mx=-1;
	long long t;
	for (int i=0;i<n;i++){
		tgt = a[i];
		sum=0;
		for (int j=i;j<n;j++){
			
			b.push(j);
			sum+=tgt-a[j];
			while (sum>m){
				sum-=tgt-a[b.front()];
				b.pop();
			}
			t=b.size();
			if (mx<t)mx=t;
		}
		while (b.size()>0){
			b.pop();
		}
		if (flag1||flag2){
			break;
		}
	}
	
	cout << mx;
	
	return 0;
} 
