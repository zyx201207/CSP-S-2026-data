#include <bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005];
bool hav[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int _ = 1;_ <= m; _++){
			hav[_] = 0;
		}
		for(int j = i;j <= n;j++){
//			cout<<"now"<<j<<" "<<a[j]<<endl; 
			hav[j] = 1;
			int ind = j-1;
			while(a[ind] != a[j] && ind >= i){
				ind--;
			}
//			cout<<ind<<" !\n";
			if(ind < i || !hav[ind]){
				continue;
			}else{
//				cout<<"do"<<endl;
				for(int k = ind+1;k < j;k++){
					hav[k] = 0;
				}
			}
//			cout<<j<<"is"<<hav[j]<<endl;
		}
		for(int j = 1;j <= m;j++){
//			cout<<hav[j]<<" "<<j<<"??"; 
			if(hav[j])cnt[a[j]]++;
		}
//		cout<<endl;
	}
	for(int i = 1;i <= m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
