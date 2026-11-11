#include<bits/stdc++.h>
using namespace std;
int n,m,s[500005],l;
struct node{
	int name,id;
}a[500005],stak[500005];
void push(node x){
	stak[l++]=x;
}
void pop(){
	l--;
}
long size(){
	return l;
}
long top1(){
	return stak[l].name;
}
long top2(){
	return stak[l].id;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].name;
		a[i].id=i;
	}
	for(int k=1;k<=n;k++){
		bool ton1[500005]={0};
        bool ton2[500005]={0}; 
		l=0;
		for(int i=k;i<=n;i++){
			if(!ton1[i]){
				if(!ton2[a[i].name]){
					push(a[i]);
					ton2[a[i].name]=1;
				}
				else{
					while(top1()!=a[i].name){
						ton1[top2()]=1;
						ton2[top1()]=0;
						pop();
					}
					ton1[top2()]=1;
					pop();
					push(a[i]);
					ton2[a[i].name]=1;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(ton2[i]==1){
				s[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
