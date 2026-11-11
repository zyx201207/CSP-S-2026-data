#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
struct nn{
	int g;
	char c;
}a[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,i,j;
	cin>>n;
	string s;
	i=1;j=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].g>>a[i].c;
	}
	while(i<=j){
		if(a[i].c!=a[j].c){
			int o=min(a[i].g,a[j].g);
			cnt+=o;
		}
		if(a[i].g>a[j].g){
			a[i].g-=a[j].g;
			j--;
		}else if(a[i].g<a[j].g){
			a[j].g-=a[i].g;
			i++;
		}else{
			j--;i++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
