#include<bits/stdc++.h>
using namespace std;

struct grid
{
    int station;
    int line;
    int ttime;
    int step=0;
    bool visited=0;
    bool trans;
};
    grid stations[500000];
int number,linenum,stationsnum,d,
    plans,weight[500005];
    
grid ttime[500005];    

int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>number>>linenum>>stationsnum>>d>>plans;
	for(int i=1;i<=stationsnum;i++)
    {
        cin>>weight[i];
    }
    int ct=1;
	for(int i=1;i<=linenum;i++)
    {
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int s,t;
            cin>>s>>t;
            stations[ct].station=s;
            stations[ct].ttime=t;
            stations[ct].line=i;
            ct++;
        }
    }
    int transed[500005]={0};
    for(int i=1;i<=ct-1;i++)
    {
        transed[stations[i].station]++;
    }
    for(int i=1;i<=ct-1;i++)
    {
        if(transed[stations[i].station]>=2)
            stations[i].trans=1;
    }
    
 
    
    
    
    for(int N=0;N<plans;N++)
    {
        for(int i=1;i<=ct;i++)
        {
			stations[i].visited=0;
		}
        
        int x0,y0;
        cin>>x0>>y0;
        queue <grid> que;
        for(int i=1;i<=ct-1;i++)
        {
            if(stations[i].station==x0)
            {
                stations[i].step=weight[x0]+stations[i].ttime;
                que.push(stations[i]);
				
            }
        }
        int minstep=99000099;
        //cout<<ct;
        while(!que.empty())
        {
            grid G=que.front();
            que.pop();
            for(int i=1;i<=ct-1;i++)
            {
                //cout<<"+";
                if(stations[i].station==y0&&stations[i].line==G.line)
                {

                    if(minstep>G.step){minstep=G.step+stations[i].ttime+weight[stations[i].station];}
                    continue;
                }
                //cout<<"+";
                if(stations[i].line==G.line&&(stations[i].visited=0||G.step<stations[i].step)&&stations[i].trans==1)
                {
                    stations[i].step=G.step;
                    
                    que.push(stations[i]);
                    
                }
                if(stations[i].station==G.station&&(stations[i].visited=0||G.step<stations[i].step))
                {
                    stations[i].step=G.step+G.ttime+stations[i].ttime;

                    
                    stations[i].visited=1;
                    que.push(stations[i]);
                }
                
			}
			
		}
		cout<<minstep;
	}
		return 0;
}

