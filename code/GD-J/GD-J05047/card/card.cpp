#include<bits/stdc++.h>
using namespace std;
int sp[1000007];
int desk[1000007];
int ans[300007];
int t[300007];
int n,m;
void clean(int d,int l){
	for(int i=1;i<l;i++){
		if(d==desk[i]){
			desk[i]=0;
			while(i<l){
				i++;
				desk[i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sp[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<1<<endl;
		memset(t,0,sizeof(t));
		memset(desk,0,sizeof(desk));
		int index=1;
		for(int j=i;j<=n;j++){
//			cout<<2<<endl;
			clean(sp[j],index);
			desk[index]=sp[j];
			index++;
		}
		for(int j=1;j<index;j++){
//			cout<<3<<endl;
			t[desk[j]]++;
		}
		for(int j=1;j<=m;j++){
//			cout<<4<<endl;
			if(t[j])ans[j]++;
		}
//		for(int j=1;j<index;j++){
//			cout<<t[i]<<" ";	
//		}
//		cout<<endl;
//		for(int j=1;j<=m;j++){
//			cout<<ans[i]<<" ";
//		}
//		cout<<endl;
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
