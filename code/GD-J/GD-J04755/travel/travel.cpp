#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt1,cnt2,cnt3;
	char  v[10],w[10];
   string a,b,c,d;
      cin>>a>>b>>c>>d;
	if(a==c) cnt1=1;
	else(cnt1=0);
	for(int i=1;i<=3;i++){
	cin>>v[i];
	for(int j=1;j<=3;j++){
	cin>>w[j];
	 if(a==c&&v[3]<='C'&&w[3]<='C'||v[3]<='E'&&v[3]>'C'&&w[3]<='E'&&w[3]>'C')
	 cnt2=1;
	else cnt2=0;
  if(w[j]-v[i]==1)cnt3=1;
 else cnt3=0;
}
}

cout<<cnt1<<cnt1<<cnt2<<cnt3;

	return 0;
}
