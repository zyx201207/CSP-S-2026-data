#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",cin);
	freopen("and.out","w",cout);
	int n,m,cnt=0,btt=0;
	cin>>n>>m;
	int a[10000000],b[10000000];
	if(m==2){
		for(int i=0;i<n;i++){
			cin>>a[i];}
		for(int q=0;q<n;q++){
			for(int w=q+1;w<n;w++){
				b[cnt]=a[q]&a[w];
				cnt++;
			}
		}
		btt=b[0];
		for(int y=0;y<cnt;y++){
			if(btt<b[y]){
				btt=b[y];
			}
			
			
		}
	}
	cout<<btt;
	return 0;
}



