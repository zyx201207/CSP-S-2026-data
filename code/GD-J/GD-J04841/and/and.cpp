#include<bits/stdc++.h>
using namespace std;
int c[200001],d[200001],m=INT_MIN;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int a,b;
	cin>>a>>b;
	
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			string sa,sb,sc;
			int q=c[i],w=c[j];
			while(q){
				sa+=q%2;
				q/=2;
			}
			while(w){
				sb+=w%2;
				w/=2;
			}
			if(sa.size()>sb.size()){
				for(int i=0;i<sb.size();i++){
					if(sa[i]==sb[i]&&sa[i]==1){
						sc+="1";
					}
					else{
						sc+="0";
					}
				}
			}
			else{
				for(int i=0;i<sa.size();i++){
					if(sa[i]==sb[i]&&sa[i]==1){
						sc+="1";
					}
					else{
						sc+="0";
					}
				}
			}
			
			
			int e=1,r=0;
			for(int i=0;i<sc.size();i++){
				r+=(sc[i]-'0')*e;
				e*=2;
			}
			if(r>m){
				m=r;
			}
		}
	}
	cout<<m;
	return 0;
}
