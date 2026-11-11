#include<bits/stdc++.h>
using namespace std;
struct node{
    long long n;
    char c;
}a[1001000];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long cnt=0,ans=0;


    cin>>n;
    deque <node> q1;
    deque <node> q2;

    for(int i=0;i<n;i++){
        cin>>a[i].n>>a[i].c;

    }

    for(int i=0;i<n;i++){
        q1.push_back({a[i].n,a[i].c});
        q2.push_back({a[n-i-1].n,a[n-i-1].c});

    }


    long long cntt=0;




    while(!(q1.empty()&&q2.empty())){
        //cout<<cntt<<" "<<q1.front().n<<" "<<q1.front().c<<" "<<q2.front().n<<" "<<q2.front().c<<endl;
        if(q1.front().n<q2.front().n){

            if(q1.front().c!=q2.front().c) cntt+=q1.front().n;
            node q2lx={q2.front().n-q1.front().n,q2.front().c};
            q1.pop_front();
            q2.pop_front();
            q2.push_front(q2lx);



        }else if(q1.front().n>q2.front().n){

            if(q1.front().c!=q2.front().c) cntt+=q2.front().n;

            node q1lx={q1.front().n-q2.front().n,q1.front().c};
            q1.pop_front();
            q2.pop_front();
            q1.push_front(q1lx);

        }else if(q1.front().n==q2.front().n){

            if(q1.front().c!=q2.front().c) cntt+=q1.front().n;

            q1.pop_front();
            q2.pop_front();

        }


    }

    cout<<cntt/2;
	return 0;
}
