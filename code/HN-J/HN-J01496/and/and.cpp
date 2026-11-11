#include<iostream>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,ans=0;
	cin >> a>> b;
	if(b==1){
		for(int q=0;q<a;q++){
			long long x;
			cin >>x;
			max(ans,x);
		}
		cout << ans;
		return 0;
	}
	if(b==a){
		cin >> ans;
		for(int q=1;q<a;q++){
			long long x;
			cin >> x;
			ans=ans&x;
		}
		cout << ans;
	} 
	
	
	return 0;
}
