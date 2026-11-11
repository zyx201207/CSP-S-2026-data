#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("ctystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	long long n,m,sum,we=0;
	cin >> n >> m;
	long long s[n];
	for(long long i=0; i<n; i++){
		cin >> s[i];
	}
	bool f=1;
	int g=abs(s[0]-s[1]);
	for(int i=1; i<n; i++){
		if(abs(s[i]-s[i-1])!=g){
			f=0;
		}
	}
	if(f==1){
		for(int i=0; i<n; i++){
			if(sum+i*g>m){
				cout << i << endl;
				return 0;
			}
			sum+=i*g;
		}
	}
	if(f==0){
		long long cz[n];
		int num[n],k;
		num[0]=0;
		sort(s,s+n);
		for(int i=1; i<n; i++){
			we=0;
			sum=0;
			for(int j=0; j<n; j++){
				if(s[i]==s[j]){
					sum++;
				}
			}
			int k,p;
			cz[i]=s[i];
			for(int j=0; j<n; j++){
				cz[j]=abs(s[j]-s[i]);
			}
			for(int j=0; j<n; j++){
				if(cz[j]==0){
					k=j;
					p=k;
					break;
				}
			}
			for(int j=k-1; j>=0; j--){
				if(cz[j]+we<=m){
					sum++;
					we+=cz[j];
				} else{
					break;
				}
			}
			num[i]=sum;
		}
		int max_num = num[1];
		for(int i=2; i<n; i++){
			max_num=max(num[i],max_num);
		}
		cout << max_num;
		return 0;
	}	
}
