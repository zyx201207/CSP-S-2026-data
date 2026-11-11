#include<iostream>
#include<algorithm>
using namespace std;
const int Maxn=200005;
int n,m;
int a[Maxn];
int temp[Maxn],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=1;i<m;i++)ans=(ans&a[i]);
	cout<<ans<<"\n";
	return 0;
}
/*
Dear hlh,

    I'm sorry to hear about that you have trouble in connecting with others.
    Don't be sad.
    You are very kind and you never shout at your classmates.
    You will make more friends in the future.
    
    Here is my advice for you to making friends.
    First,lend a hand to each your calssmates when they are in need.
    Second,talk with oters more often can help you (to?) make friends easily.
    Last,be plite to your parents.
    Always belive,parents are the most important person in our life.

    I hope you can make more friends than before.
    Best wishes for you.

                                                                    Yours,
                                                                    qyc
                                                                    
                                                                   */
