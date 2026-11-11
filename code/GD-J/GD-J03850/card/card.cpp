#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long k[a],find[b]={};
	long long y=-1;
	for(int i=0;i<a;i++){
		cin>>k[i];
		bool f=0;
		for(int j=0;j<y;j++){
			if(k[i]==find[j]){
				f=1;
			    
				break;
			}
		}
		if(f==0){
			find[y+1]=k[i];
			y++;
		}
	}
	sort(find,find+y);
	long long d[b]{};
	for(int i=0;i<a;i++){
		vector<long long> t;
		for(int j=i;j<a;j++){
			bool f=0;
			long long xb=0;
			for(int q=0;q<t.size();q++){
				if(k[j]==t[q]){
					xb=q;
					f=1;
					break;
				}
			}
			if(f=1){
				for(int r=xb;r<t.size();r++){
					t.pop_back();
				}
				t.push_back(k[i]);
			}else{
				t.push_back(k[i]);
			}
		}
		for(int j=0;j<t.size();j++){
			long long xb=0;
			for(int u=0;u<b;u++){
				if(find[u]==t[j]){
					xb=u;
					break;
				}
			}
			d[xb]++;
		}
	}
	for(int i=0;i<b;i++){
		cout<<d[i]<<endl;
	}
}
