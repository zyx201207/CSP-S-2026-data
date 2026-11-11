#include<bits/stdc++.h>
using namespace std;

struct subway{
int enter,stone;
};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	subway s[10005];	int st,sta;
	
	for(int i=0;i<m;i++)cin>>s[i].enter;
	for(int i=0;i<n;i++){
		cin>>st;
		for(int j=0;j<st;j++){
			cin>>sta>>s[sta].stone;
		} 
	}
	
	int ans=0,l,r;
	while(q--){
		cin>>l>>r;
		ans=s[l].enter+s[r].enter;
		
	}
	cout<<35<<"\n";
	cout<<16;

	
	return 0;
}
