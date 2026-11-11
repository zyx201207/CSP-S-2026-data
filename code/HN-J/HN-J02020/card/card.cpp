#include<bits/stdc++.h>
using namespace std;

int a[50010],b[30010];
string s="";
int cha(string x,char y){
	int i;
	for(i=0;i<x.size();i++){
		if(x[i]==y){
			return i;
		}
	}
	return -1;
}

void shan(int y){
	string x="";
	for(int i=0;i<y;i++){
		x=x+s[i];
	}
	s=x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(i=1;i<=n;i++){
		s=a[i]+48;
		for(j=i+1;j<=n;j++){
			char g=a[j]+48;
			int w=cha(s,g);
			if(w!=-1){
				shan(w);
			}
			
			
			s=s+g;
			
		}
		for(j=0;j<s.size();j++){
			int h=s[j]-48;
			b[h]++;
		}
	}
	for(i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
}
