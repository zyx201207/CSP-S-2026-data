#include<bits/stdc++.h>
using namespace std;
//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
int n,m;

vector<pair<string,int>> ab(200010);
long long ssum(string st){
	long long s=0;
	for(int i=0;i<st.size();i++){
		s+=(st[i]-'0');
	}
	return s;
}
void sss(pair<string,int> a){
	int w=0,a1,x=0;
	while(ssum(a.first)!=0){
		if(a.first[x]-'0'==0){
			x++;
			continue;
		}
		string b="";
		while(x!=a.first.size()-1||ssum(a.first)>=2){
			a1=(a.first[x]-'0');
			a.first[x]='0';
			if(a1<2){
				a1=a1*10+(a.first[++x]-'0');
				a.first[x]=a1/2+'0';
			}
			else{
				a.first[x]=a1%2+'0';
			}
			b+=(a1/2+'0');
			cout<<a.first<<'}'<<endl;
		}
		swap(a.first,b);
		if(a1%2){
			a.second++;
		}
		cout<<a.first<<"-------"<<a.first.size()<<endl;
		cout<<x<<endl;
		cin>>w;
		x=0;
	}
	cout<<a.second;
}/*
bool cmp(pair<string,int> a,pair<string,int> b){
	sss(a);
	sss(b);
}*/
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ab[i].first;
	}

	sss(ab[0]);
	//sort(ab.begin(),ab.end(),cmp);
	return 0;
}