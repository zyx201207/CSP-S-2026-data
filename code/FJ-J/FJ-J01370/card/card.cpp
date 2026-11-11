#include<bits/stdc++.h> 
using namespace std;
int b[1000000],a[1000000],s[1000000];
int t[300000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		t[a[i]]++;
		if(t[a[i]]>=2){
			for(int j=i-1;j>=1;j--){
				if(a[j]==a[i]){
					a[j]=0;
					break;
				}a[j]=0;
			}
		}
		if(a[i]!=0){
			s[a[i]]++;
			a[i]=b[i];
		}
	}for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			t[a[j]]=0;
		}
		for(int j=1;j<=n;j++){
			t[a[j]]++;
			if(t[a[j]]>=2){
			for(int k=i-1;k>=1;k--){
				if(a[k]==a[j]){
					a[k]=0;
					break;
				}a[j]=0;
			}
		}
		if(a[j]!=0){
			s[a[j]]++;
			a[j]=b[j];
		}
		}
		for(int j=1;j<=m;j++){
			if(a[j]!=0) s[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[a[i]]<<" ";
	}
	return 0;
}
