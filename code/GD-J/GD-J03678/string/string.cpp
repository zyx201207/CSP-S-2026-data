#include<bits/stdc++.h>
using namespace std;
long long n,l,v,f;
struct V{
	int a;
	char c;
	long long s,ss;
}t[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].c;
		t[i].s=t[i-1].ss+1;
		t[i].ss=t[i].s+t[i].a-1;
		l+=t[i].a;
	//	cout<<t[i].s<<" "<<t[i].ss<<" ";
	}
	long long x=1,y=n;
	while(x<y){
		if(t[x].c!=t[y].c){
			if(l-t[x].ss+1<t[y].s){	
				v+=t[y].ss-t[y].s+1;
				t[x].s+=t[y].ss-t[y].s+1;
				y--;
				//cout<<" a"<<x<<" "<<t[x].s<<" "<<t[x].ss<<" ";
			}
			else if(l-t[x].ss+1>t[y].s){
				v+=t[x].ss-t[x].s+1;		
				t[y].ss-=t[x].ss-t[x].s+1;
				x++;
			}
			else{
				v+=t[y].ss-t[y].s+1;
				y--;
				x++;
			}
		}
		else{
			if(l-t[x].ss+1<t[y].s){	
				t[x].s+=t[y].ss-t[y].s+1;
				y--;
			}
			else if(l-t[x].ss+1>t[y].s){		
				t[y].ss-=t[x].ss-t[x].s+1;
				x++;
			}
			else{
				y--;
				x++;
			}
		}
//		cout<<v<<" ";
	}
	cout<<v<<" ";
	return 0;
}
//3
//2 a
//2 b
//1 c
