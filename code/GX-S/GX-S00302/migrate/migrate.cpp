#include<cstdio>
#include<algorithm>
using namespace std;

const int nn=2000006;

int n;
long long m;
long long a[nn];
long long ans;

int b1[nn],b2[nn];

int c1[nn],sumc1;
int c2[nn],sumc2;
int c3[nn],sumc3;
int c4[nn],sumc4;
int c5[nn],sumc5;
int c6[nn],sumc6;

void work();
void Clear();

int main()
{
//    freopen("mine2.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int qc,qt;
    scanf("%d%d",&qc,&qt);

    while(qt--) work();

    return 0;
}
void work()
{
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    for(int i=1,j=1;i<=n;i++)
    {
        while(a[i]-a[j]>m) j++;
        b1[i]=j;
    }
    for(int i=n,j=n;i;i--)
    {
        while(a[j]-a[i]>m) j--;
        b2[i]=j;
    }

    for(int i=1,j;i<=n;i++)
    {
//        printf("w-f4-OK0 i=%d\n",i);//
//        printf("c1[]=");for(int j=1;j<=n;j++)printf("%d ",c1[j]);puts("");//
//        printf("c2[]=");for(int j=1;j<=n;j++)printf("%d ",c2[j]);puts("");//
//        printf("c3[]=");for(int j=1;j<=n;j++)printf("%d ",c3[j]);puts("");//
//        printf("c4[]=");for(int j=1;j<=n;j++)printf("%d ",c4[j]);puts("");//
//        printf("c5[]=");for(int j=1;j<=n;j++)printf("%d ",c5[j]);puts("");//
//        printf("c6[]=");for(int j=1;j<=n;j++)printf("%d ",c6[j]);puts("");//

//        {
//            int jie;
//            jie=0;
//            for(int i=1;i<=n;i++) jie+=c1[i];
//            if(jie!=sumc1){puts("wrong");exit(0);};
//            jie=0;
//            for(int i=1;i<=n;i++) jie+=c2[i];
//            if(jie!=sumc2){puts("wrong");exit(0);};
//            jie=0;
//            for(int i=1;i<=n;i++) jie+=c3[i];
//            if(jie!=sumc3){puts("wrong");exit(0);};
//            jie=0;
//            for(int i=1;i<=n;i++) jie+=c4[i];
//            if(jie!=sumc4){puts("wrong");exit(0);};
//            jie=0;
//            for(int i=1;i<=n;i++) jie+=c5[i];
//            if(jie!=sumc5){puts("wrong");exit(0);};
//            jie=0;
//            for(int i=1;i<=n;i++) jie+=c6[i];
//            if(jie!=sumc6){puts("wrong");exit(0);};
//        }

        ans+=sumc2-c2[b1[i]]+sumc5;
        ans+=c6[b1[i]];
        ans+=c3[b1[i]+1];
//        printf("w-f4-OK1  ans=%lld\n",ans);//
        if(i==n) break;

        if(a[i+1]-a[i]<=m) c1[i]++,sumc1++;

        int jie0,jie1=(i+1)-b1[i+1];

        for(int j=b1[i];j<b1[i+1];j++)
        {
            jie0=c1[j];
            c1[j]=0,sumc1-=jie0;
            if(!jie1);
            else if(jie1==1) c1[i]+=jie0,sumc1+=jie0;
            else if(jie1==2) c2[i]+=jie0,sumc2+=jie0;
            else if(jie1>=3) c3[i]+=jie0,sumc3+=jie0;

            jie0=c5[j];
            c5[j]=0,sumc5-=jie0;
            if(!jie1);
            else if(jie1==1) c5[i]+=jie0,sumc5+=jie0;
            else if(jie1>=2) c6[i]+=jie0,sumc6+=jie0;
        }

        for(int j=b1[i];j<b1[i+1];j++)
        {
            jie0=c2[j];
            c2[j]=0,sumc2-=jie0;
            if(!jie1);
            else if(jie1==1)
            {
                if(b1[i]<=j-1) c5[i]+=jie0,sumc5+=jie0;
                else if(b1[i]==j) c1[i]+=jie0,sumc1+=jie0;
            }
            else if(jie1==2)
            {
                if(b1[i]<=j-1) c6[i]+=jie0,sumc6+=jie0;
                else if(b1[i]==j)
                {
                    if(b1[i-1]==j) c2[i]+=jie0,sumc2+=jie0;
                    else c4[i]+=jie0,sumc4+=jie0;
                }
            }
            else if(jie1>=3)
            {
                if(b1[i]<=j-1);
                else if(b1[i]==j)
                {
                    if(b1[i-1]==j) c3[i]+=jie0,sumc3+=jie0;
                    else c4[i]+=jie0,sumc4+=jie0;
                }
            }

            jie0=c4[j];
            c4[j]=0,sumc4-=jie0;
            if(!jie1);
            else if(jie1==1)
            {
                if(b1[i]<=j-1);
                else if(b1[i]==j) c1[i]+=jie0,sumc1+=jie0;
            }
            else if(jie1==2)
            {
                if(b1[i]<=j-1);
                else if(b1[i]==j)
                {
                    if(b1[i-1]==j) c2[i]+=jie0,sumc2+=jie0;
                    else c4[i]+=jie0,sumc4+=jie0;
                }
            }
            else if(jie1>=3)
            {
                if(b1[i]<=j-1);
                else if(b1[i]==j)
                {
                    if(b1[i-1]==j) c3[i]+=jie0,sumc3+=jie0;
                    else c4[i]+=jie0,sumc4+=jie0;
                }
            }

            jie0=c6[j];
            c6[j]=0,sumc6-=jie0;
            if(!jie1);
            else if(jie1==1)
            {
                if(b1[i]<=j-1);
                else if(b1[i]==j) c5[i]+=jie0,sumc5+=jie0;
            }
            else if(jie1>=2)
            {
                if(b1[i]<=j-1);
                else if(b1[i]==j)
                {
                    c6[i]+=jie0,sumc6+=jie0;
                }
            }
        }

        for(int j=b1[i];j<b1[i+1];j++)
        {
            jie0=c3[j];
            c3[j]=0,sumc3-=jie0;

            if(!jie1);
            else if(jie1==1)
            {
                if(b1[i]<=j-2);
                else if(b1[i]==j-1) c5[i]+=jie0,sumc5+=jie0;
                else if(b1[i]==j) c1[i]+=jie0,sumc1+=jie0;
            }
            else if(jie1==2)
            {
                if(b1[i]<=j-2);
                else if(b1[i]==j-1) c6[i]+=jie0,sumc6+=jie0;
                else if(b1[i]==j)
                {
                    if(b1[i-1]==j) c2[i]+=jie0,sumc2+=jie0;
                    else c4[i]+=jie0,sumc4+=jie0;
                }
            }
            else if(jie1>=3)
            {
                if(b1[i]<=j-2);
                else if(b1[i]==j-1) c6[i]+=jie0,sumc6+=jie0;
                else if(b1[i]==j)
                {
                    if(b1[i-1]==j) c3[i]+=jie0,sumc3+=jie0;
                    else c4[i]+=jie0,sumc4+=jie0;
                }
            }
        }
    }

    printf("%lld\n",ans);

    return Clear();
}
void Clear()
{
    for(int i=1;i<=n;i++)
        a[i]=0,b1[i]=0,b2[i]=0,c1[i]=0,c2[i]=0,c3[i]=0,c4[i]=0,c5[i]=0,c6[i]=0;
    sumc1=0,sumc2=0,sumc3=0,sumc4=0,sumc5=0,sumc6=0;
    n=0,m=0,ans=0;
    return;
}

/*
0 1
6 12
-10 -6 -2 2 6 10
ans:1
*/
/*
0 3
9 2
1 2 3 4 5 6 7 8 9
9 3
1 2 3 4 5 6 7 8 9
9 4
1 2 3 4 5 6 7 8 9
ans:6 4 2
*/
/*
0 1
8 2
1 2 3 4 5 6 7 8
ans:5
*/
/*
0 1
8 3
1 2 3 4 5 6 7 8
ans:3
*/









/*
        for(int j=b1[i]+1;j<b1[i+1];j++)
        {
            jie0=c2[j];
            c2[j]=0,sumc2-=jie0;
            if(!jie1);
            else if(jie1==1) c5[i]+=jie0,sumc5+=jie0;
            else if(jie1>=2) c6[i]+=jie0,sumc6+=jie0;

            jie0=c4[j];
            c4[j]=0,sumc4-=jie0;

            jie0=c6[j];
            c6[j]=0,sumc6-=jie0;
        }
        if(b1[i]<b1[i+1])
        {
            int j=b1[i+1];

            jie0=c2[j];
            c2[j]=0,sumc2-=jie0;
            c1[j]+=jie0,sumc1+=jie0;

            jie0=c4[j];
            c4[j]=0,sumc4-=jie0;
            c1[j]+=jie0,sumc1+=jie0;

            jie0=c6[j];
            c6[j]=0,sumc6-=jie0;
            c5[j]+=jie0,sumc5+=jie0;
        }

        for(int j=b1[i]+2;j<b1[i+1];j++)
        {
            jie0=c3[j];
            c3[j]=0,sumc3-=jie0;
        }
        if(b1[i]<b1[i+1])
        {
            int j=b1[i+1]+1;

            jie0=c3[j];
            c3[j]=0,sumc3-=jie0;
            c2[j]+=jie0,sumc2+=jie0;
        }
        if(b1[i]+1<b1[i+1])
        {
            int j=b1[i+1];

            jie0=c3[j];
            c3[j]=0,sumc3-=jie0;
            c1[j]+=jie0,sumc1+=jie0;
        }
*/
