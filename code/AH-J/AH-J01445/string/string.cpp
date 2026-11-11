#include<bits/stdc++.h>
using namespace std;
struct MyNode{
	long long a;
	char c;
};
MyNode mynode[200005];
int n;
long long cnt=0;
bool flag=false,flag1=false;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>mynode[i].a>>mynode[i].c;
		sum+=mynode[i].a;
	}
	/*
	for(int i=1;i<n;i++){
		if(mynode[i].c==mynode[i-1].c){
			mynode[i].a+=mynode[i-1].a;
			mynode[i-1].a=0;
			mynode[i-1].c='0';
		}
	}
	for(int i=0;i<n;i++){
		if((mynode[i].a==0)&&(mynode[i].c=='0')){
			int j=0;
			while(true){
				if(mynode[j]
		}
	*/
	/*
	for(int i=0;i<n/2;i++){
		if(i==n/2-1-i){
			if(mynode[i].c==mynode[n-i-1].c){
				continue;
			}
		}
		if((mynode[i].a==mynode[n-i-1].a)&&(mynode[i].c==mynode[n-i-1].c)){
			continue;
		}else{
			if(mynode[i].a==mynode[n-i-1].a){
				cnt+=mynode[i].a;
				continue;
			}
			if(mynode[i].c==mynode[n-i-1].c){
				cnt+=max(mynode[i].a,mynode[n-i-1].a)-min(mynode[i].a,mynode[n-i-1].a);
				continue;
			}
			cnt+=max(mynode[i].a,mynode[n-i-1].a);
			continue;
		}
	}
	cout<<cnt;
	*/
	/*
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>mynode[i].a>>mynode[i].c;
	}
	int p=0;
	for(p=0;p<n-1;p++){
		if(mynode[p].c!=mynode[p+1].c){
			break;
		}
	}
	if(p==n-1){
		cout<<0;
	}
	*/
	string s,s1;
	sum/=2;
	int p=0,p1=0;
	int i=0,i1=0;
	while(p<sum&&!flag){
		if(!flag){
			for(int j=0;j<mynode[i].a;j++){
				if(p>=sum){
					flag1=true;
					break;
				}
				s+=mynode[i].c;
				p++;
			}
			i++;
		}
		if(!flag1){
			for(int j=0;j<mynode[n-i1-1].a;j++){
				if(p1>=sum){
					flag1=true;
					break;
				}
				s1+=mynode[n-i1-2].c;
				p1++;
			}
			i1++;
		}
	}
	for(int i=0;i<sum;i++){
		if(s[i]!=s1[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
