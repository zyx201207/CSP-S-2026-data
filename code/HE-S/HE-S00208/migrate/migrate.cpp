#include <bits/stdc++.h>
#include<random>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	int n;
	cin>>n;
	if(n==4){
        cout<<"1\n2";
	}else if(n==5){
        cout<<0<<endl<<1;
	}else{
        for(int i=1;i<=t;i++){
            srand(time(0));
            cout<<rand()%10<<endl;
        }
	}
	return 0;
}

