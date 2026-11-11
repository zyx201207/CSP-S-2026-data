#include<bits/stdc++.h>
using namespace std;
int N;
struct node{
	int n;
	char a;
}arr[200005];
int s[200005];
long long sum=0;
int top=0;
string str;
int l;
bool check(int l,int r,int y[]){
	while(l<=r){
		if(y[l]!=y[r]){
			return false;
		}
		l++,r--;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>arr[i].n;
		cin>>arr[i].a;
	}
	for(int i=1;i<=N;i++){
		int a1=arr[s[top]].a,a2=arr[i].a;
		int n1=arr[s[top]].n,n2=arr[i].n;
		str+=a2;
		if(top>0){
			if(a1!=a2){
				if(n1<n2){
					sum+=n1;
					arr[i].n-=n1;
				}else if(n1>n2){
				    sum+=n2;	
					arr[s[top]].n-=n2;
					top--;
				}
			}
		}
		if(n1==n2){
			continue;
		}
		top++;
		s[top]=i;
	}
	cout<<sum;
	return 0;
}
