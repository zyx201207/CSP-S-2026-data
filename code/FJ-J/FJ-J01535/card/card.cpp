#include <iostream>
using namespace std;
long long n,m,a,b[100005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		b[a]++;
	}
	for(int i=1;i<=m;i++){
		if(b[i]%2==0){
			cout<<'0'<<' ';
		}else{
			cout<<'1'<<' ';
		}
	}
	return 0;
}
