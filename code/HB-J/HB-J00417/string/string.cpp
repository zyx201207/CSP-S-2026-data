#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[200005];
ll a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,ans=0,last=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		
		//len+=s[i].length();
		for(ll j=0;j<a[i];j++){
			s[i]+=c;
		}
		//cout<<s[i];
	}
	//for(int i=1;i<=n;i++) cout<<s[i];
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<s[i].size();j++)cout<<s[i][j];}*/
	/*for(ll i=1;i<=n;i++){
		str+=s[i];
	}*/
	//ll l=0,r=str.length()-1/*,test=200005*pow(10,9)*/;
	//cout<<test;
	//ll end=len-1;
	if(n%2!=0){
		last=n/2+1;
		ll ed=0;
		for(ll i=1;i<last;i++){
			ed=n-i+1;
			string temp,next,mir;
			ll leng=min(s[i].length(),s[ed].length()),lengt=max(s[i].length(),s[ed].length());
			//cout<<s[i].size()<<" "<<s[ed].size()<<endl;
			if(s[i].length()>s[ed].length()){
				temp=s[i].substr(s[ed].length(),s[i].length()-s[ed].length());
				next=temp+s[i+1];
				s[i+1]=next;
				//cout<<temp<<" "<<next;//00000000
				for(ll j=0;j<leng;j++){
					if(s[i][j]!=s[ed][leng-j-1]){
						ans++;
					}
				}
			}
			else if(s[i].length()<s[ed].length()){
				temp=s[ed].substr(0,s[ed].length()-s[i].length());
				next=s[ed-1]+temp;
				s[ed-1]=next;
				//cout<<temp<<" "<<next;//00000000
				for(ll j=0;j<leng;j++){
					if(s[i][j]!=s[ed][lengt-j-1]){
						ans++;
					}
				}
			}
			
		}
		ll l1=0,r1=s[last].length()-1;
		while(l1<=r1){
			if(s[last][l1]!=s[last][r1]){
				ans++;
				l1++;
				r1--;
			}
			else{
				l1++;
				r1--;
			}
		}
	}
	else{
		last=n/2;
		ll ed=0;
		for(ll i=1;i<=last;i++){
			ed=n-i+1;
			string temp,next,mir;
			ll leng=min(s[i].length(),s[ed].length()),lengt=max(s[i].length(),s[ed].length());
			if(s[i].length()>s[ed].length()){
				temp=s[i].substr(s[ed].length(),s[i].length()-s[ed].length());
				next=temp+s[i+1];
				s[i+1]=next;
				//cout<<temp<<" "<<next;//00000000
				for(ll j=0;j<leng;j++){
					if(s[i][j]!=s[ed][leng-j-1]){
						ans++;
					}
				}
			}
			else if(s[i].length()<s[ed].length()){
				temp=s[ed].substr(0,s[ed].length()-s[i].length());
				next=s[ed-1]+temp;
				s[ed-1]=next;
				//cout<<temp<<" "<<next;//00000000
				for(ll j=0;j<leng;j++){
					if(s[i][j]!=s[ed][lengt-j-1]){
						ans++;
					}
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}
