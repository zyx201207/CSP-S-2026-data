#include<bits/stdc++.h>
using namespace std;
//int N = 1e6+10;
int n,m;
long long desk[1000010],hand[1000010],nd[100010],kn[100010];
int main(){
	freopen("card2.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n;i++){
		cin >> hand[i];
		kn[i] = hand[i];
		
	}int dum,hum;
	for(int i=1;i<=n;i++){
		cout << i << endl;
		dum = i-1,hum = n-dum;
		for(int j=1;j<=n;j++){
			if(j<=dum){
				desk[j] = 0;
				hand[j] = 0;
			}else{
				desk[j] = 0;hand[j] = kn[j];
			}
		}
		for(int j=i;j<=n;j++){
			cout << j << " ";
			int mi = 0;
			for(int l=dum;l>=1;l--){
				if(desk[l]==hand[j]){
					mi = l;cout << mi << " ";break;
				}
			}
			if(mi>0){
				dum=dum-mi;
				for(int k=mi+1;k<=m;k++){
					desk[k] = 0;
				}
			}//cout << desk[1] << " ";
			dum+=1;
			desk[dum] = hand[j];cout << dum <<endl;
			for(int k=1;k<=dum;k++){
				cout  << desk[k]<< " ";
			}cout << endl;
		}for(int j=1;j<=dum;j++){
			int k = desk[j];
			nd[k]++;cout <<" "<< desk[j] << " ";
		}cout << endl<< endl;
	}for(int i=1;i<=m;i++){
		cout << nd[i] << " ";
	}
}

