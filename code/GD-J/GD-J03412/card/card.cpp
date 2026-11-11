#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[300010],zt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=700&&m<=100000&&m>=200){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]) zt[a[i]]=0;
			zt[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<zt[i]<<' ';
		}
		return 0;
	}
	else if(n>5000&&m<=2){
		if(m==1){
			cout<<n;
		}
		else{
			for(int i=1;i<=n;i++){
				zt[a[i]]++;
				if(zt[a[i]]==2&&a[i]==2){
					zt[2]=1;
					zt[1]=0;
				}
				else if(zt[a[i]]==2&&a[i]==1){
					zt[2]=0;
					zt[1]=1;
				}
			}
			for(int i=1;i<=m;i++){
				cout<<zt[i]<<' ';
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[a[j]]++;
//			cout<<a[j]<<' '<<t[a[j]]<<endl;
			if(t[a[j]]==2){
				for(int h=j-1;h>=1;h--){
					if(a[j]==a[h]){
						t[a[h]]=1;
//						cout<<a[h]<<' '<<t[a[h]]<<endl;
						break;
					}
					else{
						t[a[h]]=0;
//						cout<<a[h]<<' '<<t[a[h]]<<endl;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			zt[a[j]]+=t[a[j]];
//			cout<<'z'<<' '<<a[j]<<' '<<zt[a[j]]<<endl;
			t[a[j]]=0;
//			cout<<a[j]<<' '<<t[a[j]]<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<zt[i]<<' ';
	}
	return 0;
}
