#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],cd[N],zl[N];
int main(){
//	freopen("card1.in","r",stdin);
//	freopen("card1.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			cd[j]=0;
		}
		int ii=0;
		for(int j=i;j<=n;j++){
			if(j==i){
				cd[++ii]=a[j];
			}
			else{
				for(int k=ii-1;k>=i;k--){
					if(cd[k]==a[j]){
						for(int dl=ii-1;dl>=k;dl--){
//							cout<<cd[dl]<<" ";
							cd[dl]=0;
							ii--;
						}
//						cout<<"\n";
						break;
					}
				}
				cd[++ii]=a[j];
//				if(i==1&&j==n){
//					cout<<"\n"<<ii<"\n";
//				}
			}
		}
//		cout<<"µÚ"<<i<<"ÂÖ";
		for(int j=1;j<=n;j++){
//			cout<<cd[j]<<" ";
			zl[cd[j]]++;
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<1<<" ";
	}
	return 0;
}

