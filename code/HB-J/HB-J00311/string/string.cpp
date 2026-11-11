#include<bits/stdc++.h>
using namespace std;
struct mid{
	int a;
	char b;
};
mid s[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ssum=0,z=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a;
		ssum+=s[i].a;
		cin>>s[i].b;
	}
	int j=0,bsum=0;
	while(100){
		int x=ssum/2;
		if(bsum+s[j].a>x){
			if(bsum!=x){
			b[j].b=s[j].b;
			b[j].a=x-bsum;
			s[j].a=s[j].a-x+bsum;
		}else{j--; }
			break;
		}
		b[j].b=s[j].b;
		b[j].a=s[j].a;
		bsum+=b[j].a;
		j++;
	}
	int y=j+1,x=j;
	while(b[0].a!=0){
		if(b[x].a<=s[y].a){
			s[y].a=s[y].a-b[x].a;
			if(s[y].b!=b[x].b)z+=b[x].a;
			b[x].a=0;
			x--;
		}
		if(b[x].a>s[y].a){
			if(s[y].b!=b[x].b)z+=s[y].a;
			b[x].a-=s[y].a;
			s[y].a=0;
			y++;
		}
		if(x<0)x=0;
		if(y>n-1)y=n-1;
	}
	cout<<z;
	return 0;
}
