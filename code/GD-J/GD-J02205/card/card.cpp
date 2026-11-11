#include<iostream>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	long long a[200005]={0},len=0,b[200005]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];len++;b[i]=a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			int nlen=len,ni=i;
			for(int j=1;j<ni;j++){
				if(a[i]==b[j]||nlen!=len){
					b[j]=b[j+1];
					b[j+1]=0;
					len--;
					ni--;
					j--;
				}
			}
		}
	}for(int i=1;i<len;i++){
			if(b[i]!=0)
			cout<<b[i]<<' ';
	}
	return 0;
}
