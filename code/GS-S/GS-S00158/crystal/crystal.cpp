#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,mid=0;
	long long m,p=0;
	cin>>n>>m;
	long long a=0,b;
	int t=0,ans=1;
	vector<int> c;
	for(int i=0;i<n;i++){
		cin>>b;
		c.push_back(b);
	}
	sort(c.end()-n,c.end());
	for(int i=0;i<n;i++){
		b=c[i];
		if(i==0) a=b;
		if(i!=0){
			if(b>a){
				t=(i-p)*(b-a);
				a=b;
			}else{
				t=a-b;
			}
			m-=t;
			
			if(m>=0) ans++;
			if(m<0){
				m+=(a-c[p]);
				p++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
