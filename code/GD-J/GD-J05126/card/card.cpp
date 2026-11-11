#import <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int s;
	for(int i=0;i<n;i++){
		int h=0;
		cin>>h;
		a[i]=h;
		if(h==2){
			s++;
		}
		
	}
	cout<<n<<" "<<s;
	
	
	return 0;
}
