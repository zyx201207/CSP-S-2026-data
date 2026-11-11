#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct StationPoint;

struct Station{
    int id;
    int time = 0;
    vector<StationPoint*> points;
};

struct StationPoint{
    int way;
    int time;
    Station* station;
    StationPoint* next;
};

int search(Station* start,int endId,StationPoint* lastPoint,int maxdeep,int deep,int ntime) {
    if (maxdeep == deep) return -1;
    for (StationPoint* point : start->points) {
        if (point->next == nullptr) continue;
        if (point->next->station->id == endId) {
            if (lastPoint == nullptr) {
                return ntime + point->time + point->next->time;
            } else {
                 if (point->way == lastPoint->way) {
                    return ntime + point->next->time;
                } else {
                    return ntime + lastPoint->time + point->time + point->next->time;
                }
            }
        } else {
            if (lastPoint == nullptr) {
                ntime += point->time;
            } else {
                if (point->way != lastPoint->way) {
                    ntime += lastPoint->time + point->time;
                }
            }
            int time = search(point->next->station,endId,point,maxdeep,deep + 1,ntime);
            if (time != -1)
                return time;
        }
    }
    return -1;
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    Station* stations = new Station[m];
    for (int i = 0;i < m;i++) {
        stations[i].id = i;
        cin >> stations[i].time;
    }
    for (int i = 0;i < n;i++) {
        int len;
        cin >> len;
        StationPoint* last = nullptr;
        for (int j = 0;j < len;j++) {
            int id,time;
            cin >> id >> time;

            StationPoint point;
            point.way = i;
            point.time = time;
            point.station = &stations[id - 1];

            stations[id - 1].points.push_back(&point);

            if (last != nullptr) {
                last->next = &point;
            }
        }
    }
    for (int i = 0;i < q;i++) {
        int start,end;
        cin >> start >> end;
        Station sstart = stations[start - 1];
        int time = search(&sstart,end - 1,nullptr,m,0,0);
        time += stations[start - 1].time + stations[end - 1].time;
        cout << time << endl;
    }
}
