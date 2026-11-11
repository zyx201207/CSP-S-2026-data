#include<bits/stdc++.h> 
using namespace std;
int a[1000010]; 
int c[1000010];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
   if(m==1){
   	cout<<n<<endl;
   }
   
	return 0;
}
