#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	int a;
//	cin>>a;
//	cout<<a;

	long n,m;
	cin>>n>>m;
	long sa[n];
	for(int i=0;i<n;i++){
		cin>>sa[i];
	}
	sort(sa,sa+n);
//for(int i=0;i<n;i++){
//cout<<sa[i]<<endl;
//}

	int s=1;int b=m;
	for(int i=0;i<n;i++){
		int d=i+1;//cout<<"d="<<d<<" ";
		s=d;
		int c=(sa[i+1]-sa[i]);//cout<<"c="<<c<<" ";
		//if(sa[i+1]==sa[i])s++;
		if(b<d*c)break;
		if(b>=d*c&&(b>0)){
			for(int j=0;j<d;j++){
				sa[j]+=c;
				b-=c;
				if(b<0)break;
			}//cout<<"b="<<b<<endl;
			
		}

	}
//	for(int i=0;i<n;i++){
//		if(sa[i+1]==sa[i])s++;
//		cout<<sa[i]<<" ";
//	}
	cout<<s;
	return 0;
} 
