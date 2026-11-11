#include<bits/stdc++.h>
using namespace std;
int n,top,tail;
long long k; 
struct node{
	int m;
	char ch;
};
node a[200005];
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	cin>>n;
	k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].ch;
	}
	top=1,tail=n;	
	while(top<tail){
		if(a[top].ch!=a[tail].ch){
			if(a[top].m<a[tail].m)k+=a[top].m;
			else k+=a[tail].m;
		}
		if(a[top].m>a[tail].m)a[top].m-=a[tail].m,a[tail].m=0;
		else a[tail].m-=a[top].m,a[top].m=0;
		if(a[top].m==0)top++;
		if(a[tail].m==0)tail--;
	}	
	cout<<k;
	return 0;
}

