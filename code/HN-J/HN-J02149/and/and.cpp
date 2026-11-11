#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x[200011],mmx,w;
string a[200011];
bool cmp(int x,int y){
	string subx=a[x].substr(0,w+1),suby=a[y].substr(0,w+1);
	for(int i=0;i<=w/2;i++)
		swap(subx[i],subx[w-i]),swap(suby[i],suby[w-i]);
	return subx>suby;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		x[0]=max(x[0],x[i]);
	}
	for(int i=0;i<=n;i++){
		for(;x[i]>0;x[i]>>=1)
			a[i]+=x[i]%2+48;
		while(a[i].size()<a[0].size()) 
			a[i]+='0';
	}
	for(w=a[0].size()-1;w>=0;w--){
		vector<int> xa;
		for(int j=1;j<=n;j++)
			if(a[j][w]>'0')
				xa.push_back(j);
		if(xa.size()>=m){
			sort(xa.begin(),xa.end(),cmp);
//				for(int i=0;i<xa.size();i++) cout<<a[xa[i]]<<endl;
			for(;w>=0;w--){
				int xxx=1;
				for(int i=0;i<m;i++)
					if(a[xa[i]][w]=='0'){
						xxx=0;
						break;
					}
				mmx+=xxx<<w; 
			}
		}
	}
	cout<<mmx;
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
