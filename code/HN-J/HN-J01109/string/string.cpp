#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll out;
struct str{
	ll a;
	char b;
}arr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s="";
	for(int o=0;o<n;o++){
		cin>>arr[o].a>>arr[o].b;
	}
	ll i=0;
	ll j=n-1;
	while(i<j){
		ll pai=arr[i].a;
		while(pai>0){
			if(arr[i].b==arr[j].b){
				if (pai>=arr[j].a){
					pai-=arr[j].a;
					j--;
				}
				else{
					arr[j].a-=pai;
					pai=0;
				}
			}else{
				if(pai>=arr[j].a){
					pai-=arr[j].a;
					out+=arr[j].a;
					j--;
				}else{
					arr[j].a-=pai;
					out+=pai;
					pai=0;
				}
			}
		}
		i++;
	}
	cout<<out;
	return 0;
}
