#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],s[500010],ss[300010],mj[500010][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=n;i>=1;i--){
		s[i]=1;
		
		if(b[a[i]]!=0){
			mj[i][0]=b[a[i]];
			s[b[a[i]]]+=i;
			s[i]-=i;
			if(mj[i-1][1]-mj[b[a[i]]][1]!=0){
				for(int k=i+1;k<=b[a[i]];k++){
					if(mj[k][0]){
						s[k]+=i;
						s[mj[k][0]]-=i;
					}
				}
			}
		}b[a[i]]=i;mj[i][1]=mj[i][0]+mj[i+1][1];
	}
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1];
		ss[a[i]]=s[i];
	}
	for(int i=1;i<=m;i++)cout<<ss[i]<<" ";
	
	return 0;
}//10 3 3 1 2 1 3 2 3 1 2 1
