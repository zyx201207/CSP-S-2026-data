#include<bits/stdc++.h>
using namespace std;
struct dd{
	int a;
	char s;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s2;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].s;
		s2+=b[i].s;
	}
	string s1=s2;
	reverse(s2.begin(),s2.end());
	long long cnt=0;
	if(s1==s2){
		cout<<0;
		return 0;
	}else{
		int id1=1,id2=n;
		int aa=0,bb=0;
		char a1=s1[aa],a2=s2[bb];
		while(id1<id2){
			if(a1!=a2){
				cnt+=min(b[id1].a,b[id2].a);
				int ff=min(b[id1].a,b[id2].a);
				b[id1].a=b[id1].a-ff;
				b[id2].a=b[id2].a-ff;
				if(b[id1].a==0){
					id1+=1;
					aa++;
					a1=s1[aa];
				}
				if(b[id2].a==0){
					id2=id2-1;
					bb++;
					a2=s2[bb];
				}
			}else if(a1==a2){
				cnt+=abs(b[id1].a-b[id2].a);
				if(b[id1].a>b[id2].a){
					b[id1].a=b[id1].a-b[id2].a;
					b[id2].a=0;	
					id2-=1;	
					bb++;
					a2=s2[bb];			
				}else{
					b[id2].a=b[id2].a-b[id1].a;
					b[id1].a=0;	
					id1+=1;
					aa++;
					a1=s1[aa];
				}			
			}			
		}	
	}
	cout<<cnt;
	return 0;
}
