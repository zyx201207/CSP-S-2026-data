//GZ-J00348 遵义市第十二中学 张晋宁
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a+5];
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	int big=-99999999;
	sort(c+1,c+1+a);
	if(b==2){
		for(int i=1;i<=a;i++){
			for(int j=1+i;j<=a;j++){
				if(c[i]&c[j]>big){
					big=c[i]&c[j];
				}
			}
		}	
	}
	else if(b==1){
		big=c[a];
	}
	else{
		big=c[1];
		for(int i=1;i<=a;i++){
			big=big&c[i];
		}
	}
	cout<<big;
	return 0;
}
