#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],c[N];
int z[N],to;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >>n >>m;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	for(int i=0;i<n;i++){
		int b[N];
		memset(b,0,sizeof(b));
		memset(z,0,sizeof(z));
		to=0;
//			for(int j=0;j<i;j++){
//				z[to]=a[j];
//				to++;
//				b[a[j]]++;
//			}
		for(int j=i;j<n;j++){
			if(to==0||b[a[j]]==0){
				z[to]=a[j];
				to++;
				b[a[j]]++;
			}else{
				int k=0;
				while(!z[k]==a[j]){
					k++;
				}
				while(to>=0){
					z[to]=0;
					b[a[to]]--;
					if(b[a[to]]<0){
						b[a[to]]=0;
					}
					to--;
					k--;
				}
				if(to<0){
					to=0;
				}
				z[to]=a[j];
				b[a[j]]++;
				to++;
			}
		}
//				for(int k1=0;k1<to;k1++){
//					cout <<z[k1] <<" ";
//				}
//				cout <<endl;
		for(int j=1;j<=m;j++){
			if(b[j]>0){
				c[j]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout <<c[j] <<" ";
	}
	return 0;
}
