#include<bits/stdc++.h>
using namespace std;
int l,a,cnt;
char c;
string h;
void dq(int n,char u){
	for(int i=1;i<=n;i++){
		h+=u;	
	}
}
bool pd(string er){
	string we;
	for(int i=er.size()-1;i>=0;i--){
		we+=er[i];
	}
	if(we==er){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>a>>c;
		dq(a,c);
	}
	if(pd(h)==1){
		cout<<0;
	}else{
		string wr;
		for(int i=h.size()-1;i>=0;i--){
			wr+=h[i];
		}
		for(int i=h.size()-1;i>=0;i--){
			if(h[i]!=wr[i]){
				h[i]=wr[i];
				cnt++;
				if(pd(h)==1){
					cout<<cnt;
					return 0;
				}
			}
		}	
	}

	return 0;

}
