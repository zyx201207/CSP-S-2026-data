#include<bits/stdc++.h>
using namespace std;
int cards[534567]={0},outcd[534567]={0},cnt[345678]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b,poi=0;
	cin>>a>>b;
	for(int x=0;x<a;x++){
		cin>>cards[x];
	}for(int x=0;x<a;x++){
		poi=x;
		for(int y=x;y<a;y++){
			outcd[y]=cards[y];
			for(int z=x;z<y;z++){
//				cout<<outcd[z]<<' '<<outcd[y]<<endl;
				if(outcd[z]==outcd[y]){
					for(int p=z;p<y;p++){
						outcd[p]=0;
					}break;
				}
			}
		}
//		for(int i=x;i<a;i++){
//			cout<<outcd[i]<<"   ";
//		}cout<<endl;
		for(int i=x;i<a;i++){
			cnt[outcd[i]]++;
		}outcd[534567]={0};
	}for(int x=1;x<=b;x++){
		cout<<cnt[x]<<' ';
	}
	return 0;
}
