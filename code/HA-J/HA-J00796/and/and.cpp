#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int a[n]={0};
	int x=0;
	int y=0;
	int z=0;
	int h=0;
	for(int i=0;i<n;i++){
		cin>>y;
		while(x<=30){
			if(pow(2,x)==y){
				z++;
				break;
			}
			x++;
		}
		if(z==0){
			a[h]=y;
			z=0;
			h++;
		}
	}
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
