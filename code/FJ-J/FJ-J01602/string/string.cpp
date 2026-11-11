#include<bits/stdc++.h>
using namespace std;
struct note{
	char bh;
	long long s; 
};
vector<note> a;
vector<note> b;
vector<note> s1;
long long ans;
long long zs;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	note x1;
	scanf("%lld",&x1.s);
	//scanf("%c",&x1.bh);
	cin>>x1.bh;
	s1.push_back(x1);
	zs+=x1.s;
	for(int i=1;i<n;i++){
		note x;
		scanf("%lld",&x.s);
		//scanf("%c",&x.bh);
		cin>>x.bh;
		if(x.bh==s1[i-1].bh){
			s1[i-1].s+=x.s;
		}
		else{
			s1.push_back(x);
		}
		zs+=x.s;
	}
	int f=0;
	if(zs%2==1){
		f=1;
	}
	zs=zs/2;
	long long xx=0;
	int j=0;
	for(int i=0;i<s1.size();i++){
		xx+=s1[i].s;
		if(xx<=zs){
			a.push_back(s1[i]);
		}
		else{
			note x;
			x.bh=s1[i].bh;
			x.s=s1[i].s-(xx-zs);
			if(x.s!=0){
				a.push_back(x);
			}
			s1[i].s=s1[i].s-x.s-f;
			//cout<<s1[i].s<<endl;
			j=i;
			break;
		}
	}
	for(int i=s1.size()-1;i>=j;i--){
		b.push_back(s1[i]);
	}
	int k=0;
	int i1=0;
	while(i1<b.size()&&k<a.size()){
		if(b[i1].bh!=a[k].bh){
			if(a[k].s>=b[i1].s){
				a[k].s=a[k].s-b[i1].s;
				ans+=b[i1].s;
				i1++;
			}
			else{
				b[i1].s=b[i1].s-a[k].s;
				ans+=a[k].s;
				k++;
			}
		}
		else{
			if(a[k].s>=b[i1].s){
				a[k].s=a[k].s-b[i1].s;
				i1++;
			}
			else{
				b[i1].s=b[i1].s-a[k].s;
				k++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
