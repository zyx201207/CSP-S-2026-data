#include<bits/stdc++.h>
using namespace std;
long s,cnt;
int l,x,b[4000005],a[4000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	for(int i=0;i<l;i++){
		cin>>a[i]>>b[i];
		i+=a[i];	
	}
	for(int i=0;i<l;i++){
		if(b[i]=b[i+1]){
			s++;
		}
	}
	if(s!=0){
		cout<<"0";
	}else{
		for(int i=0;i<l;i++){
			if(b[i]!=b[l-i]){
			    cnt++;	
			}
		}
		cout<<cnt;
	}
	return 0;
}
