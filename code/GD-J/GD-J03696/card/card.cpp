#include<bits/stdc++.h>
using namespace std;
//long long !!!!!!!!!
long long n,m,a[200005],ans[100005],st[6000],top=0,la[4000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		la[a[i]]=-1;
	}
	if(n>6000){
		a[n+1]=100034;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<" ";
			}
		}
		return 0;
	}
	else{
		for(int k=1;k<=n;k++){
			//cout<<k<<"\n";
			for(int i=1;i<=3000;i++) la[i]=-1;
			
			for(int i=k;i<=n;i++){
	//cout<<13;
				if(la[a[i]]!=-1){
					while(st[top]!=a[i]){
						//cout<<"out "<<st[top]<<"\n";
						la[st[top]]=-1;
						top--;
					}
						//cout<<"out "<<st[top]<<"\n";
					top--;
				}
				//cout<<"in "<<a[i]<<"\n";
				la[a[i]]=i;
				st[++top]=a[i];
			}
			while(top>0){
				ans[st[top]]++;
				//cout<<st[top]<<" "<<ans[st[top]]<<"\n";
				top--;
			}
			//cout<<"\n";
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
} 
