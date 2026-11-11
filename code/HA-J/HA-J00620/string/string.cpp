#include<bits/stdc++.h>
using namespace std;
struct abc{
	long long a;
	char c;
};
abc a[210000];
vector<abc> v;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	long long sum=0;
	int n;
	cin>>n;
	long long cnt=0;
	set<char> st;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		sum+=a[i].a;
		st.insert(a[i].c);
		if(i==1) cnt=a[i].a;
		else if(a[i].c!=a[i-1].c){
			v.push_back({cnt,a[i-1].c});
			cnt=a[i].a;
		}
		else if(a[i].c==a[i-1].c){
			cnt+=a[i].a;
		}
		else if(i==n){
			v.push_back({cnt,a[i].c});
		}
	}
	if(st.size()==1){
		cout<<0;
		return 0; 
	}
	bool flag=0;
	if(sum%2==0){
		flag=1;
	}
	sum/=2;
	stack<abc> s;
	long long sum1=0;
	int i=0;
	while(sum1<sum){
		if(sum1+v[i].a<=sum){
			s.push({v[i].a,v[i].c});
			sum1+=v[i].a;
		}
		else{
			v[i].a-=(sum-sum1);
			abc tmp;
			tmp.a=(sum-sum1);
			tmp.c=v[i].c;
			s.push(tmp);
			if(flag==0){
				if(v[i].a>1){
					v[i].a-=1;
				}
				else{
					if(v[i].a==1) i++;
					else{
						i++;
						v[i].a--;
					}
				}
			}
			break;
		}
		i++;
	}
	long long ans=sum;
	while(!s.empty()){
		abc tmp=s.top();
		s.pop();
		while(tmp.a>0){
			if(tmp.a>=v[i].a){ 
				if(tmp.c==v[i].c){
					ans-=v[i].a;
				}
				tmp.a-=v[i].a;
				i++;
			}
			else{
				if(tmp.c==v[i].c){
					ans-=tmp.a;
					v[i].a-=tmp.a;
					tmp.a=0;
				}
				else{
					v[i].a-=tmp.a;
					tmp.a=0;
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
