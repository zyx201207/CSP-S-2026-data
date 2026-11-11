#include<bits/stdc++.h>
using namespace std;
int n,num;
long long sum;

struct fi{
	int x;
	char y;
}fix[100000010];

string s;

string hws;
int main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>fix[i].x>>fix[i].y;
		num+=fix[i].x;
	}
	for(int i=0;i<n;i++){
		for(int j=fix[i].x;j>0;j--){
			s=s+fix[i].y;
		}
	}
	for(int i=n;i>0;i--){
		for(int j=fix[i-1].x;j>0;j--){
			hws=hws+fix[i-1].y;
		}
	}
	if(s==hws){
		cout<<0;
	}else{
		for(int i=0;i<num;i++){
			if(s[i]!=hws[i]){
				sum++;
			}
		}
		cout<<sum/2;
	}
	
	return 0;
}
