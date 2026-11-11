#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m,num,top;
int ans[300005];
int a[500005],t[500005];
map<int,int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int kk=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) kk=0;
	}	
	if(kk==1){
		int cnt=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]&&i!=1) cnt++;
			s[cnt]++;
		}
		int sum=0;
		for(int i=1;i<=m;i++)
			cout<<sum+s[i]<<" ",sum+=s[i];
	}
	else if(n<=200000){
		if(m==1)
			cout<<n;
		else{
			for(int i=1;i<=n;i++){
				top=0;
				s.clear();
				for(int j=i;j<=n;j++){
					if(s[a[j]]){
						while(top>s[a[j]]){
							s[t[top]]=0;
							ans[t[top]]--;
							top--;
						}
					}
					else{
						t[++top]=a[j];
						s[a[j]]=top;
						ans[a[j]]++;
					}
				} 
			}
			for(int i=1;i<=m;i++) 
				cout<<ans[i]<<" ";
		}
		
	}
	else{
		for(int i=1;i<=m;i++)
			cout<<a[i]<<" ";
	}
	return 0;
}
