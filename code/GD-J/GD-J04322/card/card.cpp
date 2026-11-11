#include<bits/stdc++.h>
using namespace std;
int l[500001],t[500001],ans[500001];
bool num[300001];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>l[i];
	for(int i=0;i<n;i++){
		memset(num,false,sizeof(num));
		for(int j=i;j<n;j++){
			t[j]=l[j];
			if(!num[l[j]])num[l[j]]=true;
			else{
				for(int k=j-1;k>0;k--){
					
					if(t[k]!=l[j]){t[k]=0;ans[t[k]]++;}
					else k=0;
				}
			}
		}
	}
	memset(num,false,sizeof(num));
	for(int i=0;i<n;i++){
		if(!num[l[i]]){
			cout<<ans[l[i]]<<" ";
			num[l[i]]=true;
			
		}
		else continue;
	}
	return 0;
}
