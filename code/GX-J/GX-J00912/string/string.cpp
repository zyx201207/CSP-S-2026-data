#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sta[200010],ta,i=1,ti=0;
char tc;
string st1;

bool hwcheck(){
	ll j,k=0;
	for(j=ti;j>=ti/2;j--){
		cout<<st1[k]<<k<<" "<<sta[k]<<"-"<<st1[j]<<j<<sta[j]<<endl;
		if(!(st1[j]==st1[k]&&sta[j]==sta[k]))return 0;
		k++;
	}
	return 1;
}



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	cin>>sta[0]>>st1;
	while(i<n){
		cin>>ta>>tc;
		if(tc!=st1[ti]){
			ti++;
			sta[ti]=ta;
			//cout<<i<<" "<<ta<<endl;
			st1+=tc;
			//cout<<ti<<st1<<" "<<tc<<endl;
			i++;
			continue;
		}
		if(tc==st1[ti]){
			sta[ti]+=ta;
			cout<<"mmm"<<i<<" "<<ta<<endl;
		}
		i++;
	}
	//cout<<ti<<st1;
	//cout<<sta[0]<<" "<<sta[1]<<" "<<sta[2]<<endl;
	if(hwcheck()){
		cout<<0<<endl;
		return 0;
	}
	
	return 0;
}
