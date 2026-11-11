#include <bits/stdc++.h>
using namespace std;
#define LL long long

int c,t,n;
LL d;
struct nd
{
    int ly;
    LL v;
    vector<int> son;
};
vector<nd>tree;
vector<LL>a;
int p;
unordered_map<int,int>vis;//idx,least_layer
unordered_map<int,int>cnt;//idx,count
int fd(int i)
{
    auto f=lower_bound(a.begin()+i,a.begin()+n,a[i]+d);
    return (int)(f-a.begin());
}
//search for farthest
void show(int i)
{
    for(int ii=0;ii<tree[i].ly;ii++)cerr<<' ';
    cerr<<i<<','<<tree[i].v<<'|'<<endl;
    for(int ii=0;ii<tree[i].son.size();ii++)
    {
        show(tree[i].son[ii]);
    }
}
bool build(int i,int ly)
{
    show(1);
    for(auto ii : vis)
    {
        cerr<<"{"<<ii.first<<':'<<ii.second;
    }
    cerr<<endl;
    if(vis.find(i)==vis.end() || vis[a[i]]==ly)
    {
        int ft=p;
        int f=fd(i);

        tree[p].ly=ly;
        tree[p].v=a[i];
        if(f>=n)
                {
                    f=0;
                }

        vis[i]=ly;
        cnt[i]++;

        for(int idx=f;idx>=i+1;idx--)
        {

            if(build(idx,ly+1))
            {
                p++;
                tree[ft].son.push_back(p);
            }

        }
        return 1;

    }
    return 0;

}

int main()
{

    freopen("migrate1.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    cerr<<c<<' '<<t<<endl;
    while(t--)
    {
        int cnnt=0;
        cin>>n>>d;
        tree.resize(n);
        a.resize(n);
        a.clear();
        tree.clear();
        vis.clear();
        cnt.clear();
        p=0;
        cerr<<n<<' '<<d<<endl;
        for(int i=0;i<n;++i)
        {

            cin>>a[i];
            //cerr<<a[i]<<' ';
        }
        //cerr<<endl;
        //cerr<<'/';
        build(1,1);
        //show(0);
        for(auto i:cnt)
        {
            if(i.second==2)cnnt++;
        }
        cout<<cnnt+1<<endl;
        //cerr<<cnnt<<endl;
        /*
        short f[6000][6000]={{0}};
        for(int i=0;i<n;++i)
        {
            int r=fd(i,a,n,d);
            for(int l=i+1;l<=r;l++)
            {
                f[i][l]=1;
            }
            for(int l=i+1;l<=r;l++)
            {
                int rr=fd(l,a,n,d);
                for(int ll=l+1;ll<=rr;ll++)
                {
                    if(f[i][ll]==0)
                    {
                        f[l][ll]=1;
                    }
                    else f[l][ll]=0;
                }
            }
            for(int l=i+1;l<=r;l++)
            {
                int cnnt=0;
                for(int ll=i+1;ll<=r;ll++)
                {
                    cnnt+=f[ll][l];
                }
                if(cnnt==2)cnt++;
            }
        }
        cout<<cnt<<endl;*/
        cerr<<"__________________"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}


