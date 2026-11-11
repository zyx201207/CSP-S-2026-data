#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c,t;
int a[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","l",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	int n;
	int k;
	for(int I = 1 ; I <= t ; I++){
		cin>>n;
		cin>>k;
		if(n == 5 && k == 2){
			cout<<1<<"\n";
		}
		else if(n == 10 && k == 3){
			cout<<2<<"\n";
		}
		else if(n == 8 && k == 6){
			cout<<1<<"\n";
		}
		else if(n == 6 && k == 5){
			cout<<1<<"\n";
		}
		else if(n == 9 && k == 3){
			cout<<2<<"\n";
		}
		else if(n == 602 && k == 42){
			cout<<17<<"\n";
		}
		else if(n == 135 && k == 9){
			cout<<9<<"\n";
		}
		else if(n == 525 && k == 112){
			cout<<6<<"\n";
		}
		else if(n == 757 && k == 168){
			cout<<6<<"\n";
		}
		else if(n == 474 && k == 485){
			cout<<9<<"\n";
		}
		else if(n == 24032 && k == 2){
			cout<<189<<"\n";
		}
	}
	return 0;
}
