#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;

int n;
int sum;

struct cwz{
	int shu;
	char mu;
}an[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>an[i].shu>>an[i].mu;
	for(int i=1,j=n;i<=j;){
		if(an[i].mu!=an[j].mu){
			if(an[i].shu>an[j].shu){
				sum+=an[j].shu;
				an[i].shu-=an[j].shu;
				j--;
			} else {
				sum+=an[i].shu;
				an[j].shu-=an[i].shu;
				i++;
			}
		} else {
			if(an[i].shu>an[j].shu){
				an[i].shu-=an[j].shu;
				j--;
			} else {
				an[j].shu-=an[i].shu;
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}

