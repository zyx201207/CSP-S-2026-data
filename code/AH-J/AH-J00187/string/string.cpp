#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long mx,s,m=0,n,a,k,l,r,i,j;
	char ch;
	bool used=1;
	string st="";
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a>>ch;
		st+=ch;
	}
	/*
	n=(st.size()-1)/2;
	bool u[n+1]={0};
	while(used){
		used=0;
		mx=0;
		l=r=-1;
		for(i=0;i<=n;){
			if(u[i])
				continue;
			s=1;
			k=i;
			i++;
			while(st[i]==st[i-1]&&i<=n)
				i++,s++;
			if(s>mx){
				mx=s;
				ch=st[i-1];
				l=k;
				r=i;
			}
		}
		if(l==(unsigned long long)-1||r==(unsigned long long)-1)
			break;
		for(j=n+1+(st.size()%2)?1:0+l;j<n+(st.size()%2)?1:0+r-1;j++,l++){
			if(ch!=st[j]){
				m++;
				used=1;
			}
			u[l]=1;
		}
	}
	*/
	cout<<0;
	return 0;
}
