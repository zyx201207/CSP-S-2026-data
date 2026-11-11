#include<iostream>
using namespace std;
int n,m,a[500005],card[500005],end[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int game=1;game<=n;game++){
		int num=0;
		for(int i=game;i<=n;i++){
			card[++num]=a[i];
			for(int j=1;j<=num-1;j++){
				if(card[j]==card[num]){
					for(int k=j;k<=num;k++){
						card[k]=0;
					}
					num=j-1;
					card[++num]=a[i];
					break;
				}
			}
		}
		for(int i=1;i<=num;i++){
			end[card[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<end[i]<<' ';
	}
	return 0; 
}
