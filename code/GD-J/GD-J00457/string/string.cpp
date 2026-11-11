#include<iostream>
using namespace std;
#define ll long long
int n,m;
ll sum=0;
pair<int,char> ls[200010],l1[200010],l2[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>ls[i].first>>ls[i].second;
	for(int i=0,j=n-1;i<j;){
		if(ls[i].first<ls[j].first){
			l1[m]={ls[i].first,ls[i].second};
			l2[m++]={ls[i].first,ls[j].second};
			ls[j].first-=ls[i].first;
			ls[i].first=0;i++;
		}
		else if(ls[i].first>ls[j].first){
			l1[m]={ls[j].first,ls[i].second};
			l2[m++]={ls[j].first,ls[j].second};
			ls[i].first-=ls[j].first;
			ls[j].first=0;j--;
		}
		else{
			l1[m]={ls[i].first,ls[i].second};
			l2[m++]={ls[j].first,ls[j].second};
			ls[i].first=0;i++;
			ls[j].first=0;j--;
		}
	}
	for(int i=0;i<m;i++)
		if(l1[i].second!=l2[i].second)
			sum+=l1[i].first;
	cout<<sum;
}
