#include<bits/stdc++.h>
using namespace std;
int www,n,m,d,q;
int a[500005],b[500005],c[500005],u[500005],l[500005],ook[500005],bs=1,cs=1,us=1;
void ch(long l,long r){
	for(int i=0;i<=u[1];i++){
		if(b[i]==l){
			for(int j=0;j<=n;j++){
				if(b[j]==r){
					l=i;
					r=j;
					break;
				}
			}
		}
	}
	long long sum=a[l]+a[r]+1;
	for(int i=l;i<=r;i++){
		sum+=c[i];
	}
	cout<<sum<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    cin>>www>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		u[us]=x+1;
		for(int j=u[us-1];j<=u[us];j++){
		   cin>>b[j]>>c[j];
		   ook[b[j]]++;
	    }
	    us++;
}
long long ls,rs;
	for(int i=1;i<=q;i++){
		cin>>ls>>rs;
		ch(ls,rs);
	}
}
//欧不不不，这种把我的脑子高炸的题无疑是绝望的，t3都没这题俄型，QAQ，较的时候都写不万，并且这个垃圾输入法无疑是男用的，就不能用一个现代的拴如法麻，看这字大的，QWQ，TVT，这1等岁分2区，欧欧欧，充满鲜花的世界到底在那里～。
