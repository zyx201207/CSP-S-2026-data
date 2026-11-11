#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],head,tail,ans[500001],flag,t[500001],pos;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	head=1;
	tail=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
		if(i==n){
			continue;
		}
		tail=0;
		for(int j=i;j<=n;j++){
			flag=0;
			if(t[a[j]]==0){
				b[tail+1]=a[j];
				t[a[j]]+=1;
				tail++;
			}
			else{
				for(int z=1;z<=tail;z++){
					if(flag){
						t[b[z]]-=1;
						b[z]=0;
					}
					if(b[z]==a[j]){
						flag=1;
						pos=z;
					}
				}
				tail=pos;
			}
			//cout<<t[1]<<" "<<t[2]<<" "<<t[3]<<tail<<endl;
		}
		for(int j=1;j<=tail;j++){
			ans[b[j]]++;
		}
	}
	ans[a[n]]++;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
} 
